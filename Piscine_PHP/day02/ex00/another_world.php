#!/usr/bin/php
<?php
	if ($argc > 1) {
		$temp = preg_replace("/(^[\s]+)|([\s]+$)/", "", $argv[1]);
		echo (preg_replace("/[\s]+/", " ", $temp)."\n");
	}
?>
