<?php
/**
 * @file
 * Contains CablecastController, CablecastChannel, CablecastShow, CablecastScheduleItem
 */

class CablecastController {
  
  private $cablecastServer;
  private $soapClient;
  private $cachedChannels = null;
  
  function __construct($serverAddress) {
    $this->cablecastServer = $serverAddress;
    $this->soapClient = new SoapClient($this->cablecastServer . '/CablecastWS/CablecastWS.asmx?WSDL', array('cache_wsdl' => 0));
  }

  public function getChannels() {
    
    //Return immediately if channels have already been cached
    if($this->cachedChannels != null) {
      return $this->cachedChannels;
    }
    
    //Lookup channels from server
    $result = $this->soapClient->GetChannels(NULL);
    $this->cachedChannels = array();
    
    foreach ($result->GetChannelsResult->Channel as $channel) {
      $this->cachedChannels[] = new CablecastChannel($channel->ChannelID, $channel->Name, $channel->PrimaryLocationID);
    }

    return $this->cachedChannels;
  }

  public function getSchedule($channelID, $fromDate, $toDate) {
    //Create $params for web service call
    $params = array('ChannelID' => $channelID,
                'FromDate' =>  $fromDate->format('Y-m-d\T00:00:00'),
                'ToDate'  =>  $toDate->format('Y-m-d\T23:59:59'),
                'restrictToShowID'  =>  0,
                );
    
    //Get Data from WebService
    $result = $this->soapClient->GetCGExemptScheduleInformation($params);
    
    //Create CablecastScheduleItems if results are returned.
    $schedule = array();
    if($result->GetCGExemptScheduleInformationResult->ScheduleInfo) {
      foreach ($result->GetCGExemptScheduleInformationResult->ScheduleInfo as $run) {
        $schedule[] = new CablecastScheduleItem($run->ScheduleID,
          $run->ShowID,
          $run->ShowTitle,
          new DateTime($run->StartTime),
          new DateTime($run->EndTime),
          $run->CGExempt);
      }
    }

    //return schedule items
    return $schedule;
  }

  public function getModifiedShows($locationID, $searchDate) {
    $params = array(
      "LocationID" => $locationID, 
      "SearchDate" => $searchDate->format('Y-m-d\T00:00:00'), 
      "DateComparator" => ">"
      );

    $result = $this->soapClient->LastModifiedSearch($params);

    $shows = array();
    foreach ($result->LastModifiedSearchResult->ShowInfo as $show) {
      $shows[] = new CablecastShow(
        $show->ShowID,
        $show->InternalTitle,
        $show->Title,
        $show->Comments,
        $show->TotalSeconds
        );
    }

    return $shows;
  }

  public function getLocations() {
    $result = $this->soapClient->getLocations(NULL);

    $result = is_array($result->GetLocationsResult->Location) ? $result->GetLocationsResult->Location : array($result->GetLocationsResult->Location);

    $locations = array();

    foreach($result as $location) {
      $locations[] = new CablecastLocation($location->LocationID, $location->Name);
    }

    return $locations;
  }
}

class CablecastLocation {
  private $name;
  private $id;

  function __construct($id, $name) {
    $this->name = $name;
    $this->id = $id;
  }

  public function getName() {
    return $this->name;
  }

  public function getID() {
    return $this->id;
  }
}

class CablecastChannel {
  private $channelID;
  private $channelName;
  private $locationID;

  function __construct($id, $name, $locationID) {
    $this->channelID = $id;
    $this->channelName = $name;
    $this->locationID = $locationID;
  }

  public function getID() {
    return $this->channelID;
  }

  public function getName() {
    return $this->channelName;
  }

  public function getLocationID() {
    return $this->locationID;
  }
}

class CablecastShow  {
  
  function __construct($showID, $title, $cgTitle, $comments, $lengthInSeconds) {
    $this->showID = $showID;
    $this->title = $title;
    $this->cgTitle = $cgTitle;
    $this->comments = $comments;
    $this->lengthInSeconds = $lengthInSeconds;
  }

  /**
   * $title Cablecast Show Title
   **/
  private $title;
  public function getTitle() {
    return $this->title;
  }

  /**
   * $CGTitle
   **/
  private $cgTitle;
  public function getCGTitle() {
    return $this->cgTitle;
  }

  /**
   * $LengthInSeconds
   **/
  private $lengthInSeconds;
  public function getLengthInSeconds() {
    return $this->lengthInSeconds;
  }

  /**
   * comments
   **/
  private $comments;
  public function getComments() {
    return $this->comments;
  }
}

class CablecastScheduleItem {

  function __construct($scheduleID, $showID, $showTitle, $startTime, $endTime, $cgExempt) {
    $this->showID = $showID;
    $this->title = $showTitle;
    $this->startDateTime = $startTime;
    $this->endDateTime = $endTime;
  }

  /**
   * Title
   */
  private $title;
  public function getTitle() {
    return $this->title;
  }

  private $showID;
  public function getShowID() {
    return $this->showID;
  }

  /**
   * RunDateTime
   */
  private $startDateTime;
  public function getStartDateTime() {
    return $this->startDateTime;
  }

  private $endDateTime;
  public function getEndDateTime() {
    return $this->endDateTime;
  }
}