#!/usr/bin/php
<?php
	function ft_is_sort($tab) {
		$test = $tab;
		sort($test);

		$flag = 0;
		$i = 0;
		$word_counter = count($test);
		while ($i < $word_counter) {
			if ($test[$i] != $tab[$i])
				$flag = 1;
			$i++;
		}
		if ($flag == 1)
			return (0);
		else
			return (1);
	}
?>
