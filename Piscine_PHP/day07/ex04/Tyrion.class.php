<?php

	class Tyrion extends Lannister {

		public function sleepWith($who) {

			if (get_class($who) == 'Jaime') {
				print("Not even if I'm drunk !" . PHP_EOL);
			}
			else if (get_class($who) == 'Sansa') {
				print("Let's do this." . PHP_EOL);
			}
			else if (get_class($who) == 'Cersei') {
				print("Not even if I'm drunk !" . PHP_EOL);
			}
		}
	}
?>