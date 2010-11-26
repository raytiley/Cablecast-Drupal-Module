<div type="text" id="cablecast_schedule_datepicker" style="float:right"></div>
  <script>
  	$(function() {
  		$("#cablecast_schedule_datepicker").datepicker({
      onSelect: function(dateText, inst) { window.location.href = location.href.substring(0,location.href.lastIndexOf("?"))+"?date="+dateText},
      });
  	});
  	</script>
<?php print $schedule_table ?>