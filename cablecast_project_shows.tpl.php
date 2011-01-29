<?php //Setup Schedule Table Variables ?>
<?php $shows_table_header = array(t("Show Title"), t("Show Description"), t("Link")); ?>
<?php $shows_table = array() ?>

<?php //Iterate through project shows and add a row for each run ?>
<?php if($project_node->cablecast_shows): ?>
	<?php foreach($project_node->cablecast_shows as $show): ?>
		<?php $shows_table[] = array(check_markup($show->title), check_markup($show->body), l('View More', 'node/'.$show->nid)) ?>
	<?php endforeach ?>
<?php endif ?>

<div class="cablecast-project-shows">
  <?php print theme_table($shows_table_header, $shows_table) ?>
	<?php print theme('pager', NULL, variable_get('cablecast_project_shows_per_page',20), 0) ?>
</div>
