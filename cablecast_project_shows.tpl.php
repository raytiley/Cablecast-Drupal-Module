<?php
$node = $variables[0];
$output = "<div class=\"cablecast-project-shows\">\n".
			  "<table class=\"cablecast-project-shows-list\">\n".
			  "<tr><th>Show Title</th><th>Show Description</th><th>Link</th></tr>\n";
	foreach($node->cablecast_shows as $show)  {
		$output = $output."<tr><td>".check_markup($show->title)."</td><td>".check_markup($show->body)."</td><td>".l('View More', 'node/'.$show->nid)."</td></tr>\n";
	}
	$output = $output."</table>". theme('pager',array(), variable_get('cablecast_project_shows_per_page',20)). " </div>\n";
	print $output;

