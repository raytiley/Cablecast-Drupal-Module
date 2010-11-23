<?php
// $Id: cablecast.views.inc,v 1.1 2010/07/20 22:18:47 raytiley Exp $
function cablecast_views_data() {
	$data['cablecast_show']['table']['group'] = t('Cablecast Shows');
	$data['cablecast_schedule_event']['table']['group'] = t('Cablecast Schedule Events');
	
	$data['cablecast_schedule_event']['table']['base'] = array(
		'field'  =>  'nid',
		'title'  =>  t('Cablecast Schedule Events'),
		'help'  =>  t('Cablecast Schedule Events contain data about scheduled runs'),
		'weight' =>  -10,
		);
		
	$data['cablecast_schedule_event']['table']['join'] = array(
		'node' => array(
			'left_field'  =>  'nid',
			'field'  =>  'nid',
			),
		);
		
	$data['cablecast_schedule_event']['nid'] = array(
	    'title' => t('Cablecast Schedule Event'),
	    'help' => t('Cablecast Schedule Event references a node.'),
	    'relationship' => array(
	      'base' => 'node',
	      'field' => 'nid',
	      'handler' => 'views_handler_relationship',
	      'label' => t('Cablecast Schedule Event node'),
	    ),
	  );
	
	$data['cablecast_schedule_event']['showID'] = array(
	    'title' => t('Cablecast ShowID '),
	    'help' => t('Cablecast Schedule Event references a Cablecast Show.'),
		'field' => array(
	      'handler' => 'views_handler_field_numeric',
	      'click sortable' => TRUE,
	     ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
		),
	    'relationship' => array(
	      'base' => 'cablecast_show',
	      'field' => 'showID',
	      'handler' => 'views_handler_relationship',
	      'label' => t('Cablecast Show Record'),
	    ),
		'argument' => array(
	      'handler' => 'views_handler_argument_numeric',
	    ),
	  );
	
	$data['cablecast_schedule_event']['cablecast_show_nid'] = array(
	    'title' => t('Cablecast Show NID '),
	    'help' => t('Cablecast Schedule Event references a Cablecast Show.'),
		'field' => array(
	      'handler' => 'views_handler_field_numeric',
	      'click sortable' => TRUE,
	     ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
		),
	    'relationship' => array(
	      'base' => 'cablecast_show',
	      'field' => 'nid',
	      'handler' => 'views_handler_relationship',
	      'label' => t('Cablecast Show Record'),
	    ),
		'argument' => array(
	      'handler' => 'views_handler_argument_numeric',
	    ),
	  );
	
	$data['cablecast_schedule_event']['scheduleID'] = array(
	    'title' => t('Cablecast ScheduleID'),
	    'help' => t('Cablecast ScheduleID'),
	    'field' => array(
	      'handler' => 'views_handler_field_numeric',
	      'click sortable' => TRUE,
	     ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
	  );
	
	$data['cablecast_schedule_event']['start_time'] = array(
	    'title' => t('Cablecast StartTime'),
	    'help' => t('DateTime of Cablecast StartTime'),
	    'field' => array(
	      'handler' => 'views_handler_field_date',
	      'click sortable' => TRUE,
	     ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_date',
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
		'argument' => array(
	      'handler' => 'views_handler_argument_date',
	    ),
	  );
	
	$data['cablecast_schedule_event']['end_time'] = array(
	    'title' => t('Cablecast EndTime'),
	    'help' => t('DateTime of Cablecast EndTime'),
	    'field' => array(
	      'handler' => 'views_handler_field_date',
	      'click sortable' => TRUE,
	     ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_date',
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
		'argument' => array(
	      'handler' => 'views_handler_argument_date',
	    ),
	  );
	
	$data['cablecast_schedule_event']['run_bump'] = array(
	    'title' => t('Cablecast RunBump'),
	    'help' => t('Number of Seconds a Run is Bumped'),
	    'field' => array(
	      'handler' => 'views_handler_field_numeric',
	      'click sortable' => TRUE,
	     ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
	  );
	
	$data['cablecast_schedule_event']['cg_exempt'] = array(
	    'title' => t('Cablecast CGExempt'),
	    'help' => t('Boolean of if a show is CG Exempt or not'),
	    'field' => array(
	      'handler' => 'views_handler_field_numeric',
	      'click sortable' => TRUE,
	     ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
	  );
	
	$data['cablecast_show']['table']['base'] = array(
		'field'  =>  'nid',
		'title'  =>  t('Cablecast Shows'),
		'help'  =>  t('Cablecast Shows contains meta data for cablecast show records'),
		'weight' =>  -10,
		);
		
	$data['cablecast_show']['table']['join'] = array(
	    'node' => array(
	      'left_field' => 'nid',
	      'field' => 'nid',
	    ),
	  );
	
	$data['cablecast_show']['nid'] = array(
	    'title' => t('Cablecast show'),
	    'help' => t('Cablecast show references a node.'),
	    'relationship' => array(
	      'base' => 'node',
	      'field' => 'nid',
	      'handler' => 'views_handler_relationship',
	      'label' => t('Cablecast Show node'),
	    ),
	  );
	
	$data['cablecast_show']['showID'] = array(
	    'title' => t('Cablecast ShowID'),
	    'help' => t('CablecastShowID'),
	    'field' => array(
	      'handler' => 'views_handler_field_numeric',
	      'click sortable' => TRUE,
	     ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
		'argument' => array(
	      'handler' => 'views_handler_argument_numeric',
	    ),
	  );
	
	$data['cablecast_show']['internalTitle'] = array(
	    'title' => t('Cablecast Shows public title'),
	    'help' => t('This is the Title field in Cablecast.'),
	    'field' => array(
	      'handler' => 'views_handler_field',
	      'click sortable' => TRUE,
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_string',
	    ),
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
	    ),
	  );
	
	$data['cablecast_show']['trt'] = array(
	    'title' => t('Total Run Time'),
	    'help' => t('Total Run Time in Seconds'),
	    'field' => array(
	      'handler' => 'views_handler_field_numeric',
	      'click sortable' => TRUE,
	     ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
	  );
	
	$data['cablecast_show']['category_id'] = array(
	    'title' => t('Category ID'),
	    'help' => t('Category ID'),
	    'field' => array(
	      'handler' => 'views_handler_field_numeric',
	      'click sortable' => TRUE,
	     ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
	  );
	
	$data['cablecast_show']['producer_id'] = array(
	    'title' => t('ProducerID'),
	    'help' => t('ProducerID'),
	    'field' => array(
	      'handler' => 'views_handler_field_numeric',
	      'click sortable' => TRUE,
	     ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
	  );
	
	$data['cablecast_show']['rating'] = array(
	    'title' => t('Rating'),
	    'help' => t('Cablecast Show Rating'),
	    'field' => array(
	      'handler' => 'views_handler_field',
	      'click sortable' => TRUE,
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_string',
	    ),
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
	    ),
	  );
	
	$data['cablecast_show']['dsk_bug_text'] = array(
	    'title' => t('Bug Text'),
	    'help' => t('Cablecast Shows Bug Text'),
	    'field' => array(
	      'handler' => 'views_handler_field',
	      'click sortable' => TRUE,
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_string',
	    ),
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
	    ),
	  );
	
  $data['cablecast_show']['streaming_file_url'] = array(
	    'title' => t('Streaming File URL'),
	    'help' => t('Cablecast Shows Streaming File URL'),
	    'field' => array(
	      'handler' => 'views_handler_field',
	      'click sortable' => TRUE,
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_string',
	    ),
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
	    ),
	  );
	$data['cablecast_show']['dsk_crawl_text'] = array(
	    'title' => t('Crawl Text'),
	    'help' => t('Shows Crawl Text'),
	    'field' => array(
	      'handler' => 'views_handler_field',
	      'click sortable' => TRUE,
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_string',
	    ),
	    'argument' => array(
	      'handler' => 'views_handler_argument_string',
	    ),
	  );
	
	$data['cablecast_show']['crawl_length'] = array(
	    'title' => t('Crawl Length'),
	    'help' => t('Length in seconds of Crawl'),
	    'field' => array(
	      'handler' => 'views_handler_field_numeric',
	      'click sortable' => TRUE,
	     ),
	    'filter' => array(
	      'handler' => 'views_handler_filter_numeric',
	    ),
	    'sort' => array(
	      'handler' => 'views_handler_sort',
	    ),
	  );
	
	return $data;
}

function cablecast_views_handlers() {
	return array(
		'info' => array(
			'path'  =>  drupal_get_path('module', 'cablecast'),
		),
		'handlers'  =>  array(
			'cablecast_handler_argument_start_time' => array(
				'parent' => 'views_handler_argument_date',
			),
		),
	);
}
