<div type="text" id="cablecast_schedule_datepicker" style="float:right"></div>
<!-- Set up jquery ui calendar -->
  <script>
  	$(function() {
  		$("#cablecast_schedule_datepicker").datepicker({
      onSelect: function(dateText, inst) { window.location.href = location.href.substring(0,location.href.lastIndexOf("?"))+"?date="+dateText},
      });
  	});
  	</script>
<?php $schedule_table_header = array(t("Time"), t("Program Name")); ?>
<?php $schedule_table = array() ?>
<?php if($schedule_nodes): ?>
	<?php foreach($schedule_nodes as $schedule_run): ?>
		<?php $schedule_table[] = array(date("h:i", $schedule_run->start_time), l($schedule_run->title, "node/".$schedule_run->cablecast_show_nid)) ?>
	<?php endforeach ?>
	
	<?php print theme_table($schedule_table_header, $schedule_table) ?>
<?php endif ?>
