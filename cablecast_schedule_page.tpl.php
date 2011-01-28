<?php drupal_set_title("$channel_name Schedule for ".date("F jS o", $schedule_date)) ?>

<?php //Setup Schedule Table Variables ?>
<?php $schedule_table_header = array(t("Time"), t("Program Name")); ?>
<?php $schedule_table = array() ?>

<?php //Iterate through schedule nodes and add a row for each run ?>
<?php if($schedule_nodes): ?>
	<?php foreach($schedule_nodes as $schedule_run): ?>
		<?php $schedule_table[] = array(date("h:i", $schedule_run->start_time), l($schedule_run->title, "node/".$schedule_run->cablecast_show_nid)) ?>
	<?php endforeach ?>
<?php endif ?>

<div id="cablecast_schedule_container">

	<div id="cablecast_schedule_table" style="float:left">
		<?php print theme_table($schedule_table_header, $schedule_table) ?>
	</div><!-- End cablecast_schedule_table -->
	
	<div type="text" id="cablecast_schedule_datepicker" style="float:left;margin-left:15px">
	<!-- Set up jquery ui calendar -->
  	<script>
  	$(function() {
  			$("#cablecast_schedule_datepicker").datepicker({
     	 onSelect: function(dateText, inst) { window.location.href = location.href.substring(0,location.href.lastIndexOf("?"))+"?date="+dateText},
     	 });
  		});
  	</script>
  </div><!-- End cablecast_schedule_datepicker -->
</div><!-- End cablecast_schedule_container -->
