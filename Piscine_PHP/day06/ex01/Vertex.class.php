<?php
	class Vertex {

		private $_x;
		private $_y;
		private $_z;
		private $_w = 1.0;
		private $_color;

		static $verbose = FALSE;

		static function doc() {

			if ($str = file_get_contents('../ex01/Vertex.doc.txt')) {
				echo "$str";
			}
			else {
				echo "Error: .doc file doesn't exist.\n";
			}
		}

		public function __construct(array $xyzwcolor) {

			if (isset($xyzwcolor['x']) &&
				isset($xyzwcolor['y']) &&
				isset($xyzwcolor['z'])) {	$this->_x = $xyzwcolor['x'];
											$this->_y = $xyzwcolor['y'];
											$this->_z = $xyzwcolor['z'];
										}

			if (isset($xyzwcolor['w'])) {
				$this->_w = $xyzwcolor['w'];
			}

			if (isset($xyzwcolor['color'])) {
				$this->_color = $xyzwcolor['color'];
			}
			else {
				$this->_color = new Color(array('red' => 255,
												'green' => 255,
												'blue' => 255
																));
			}

			if (self::$verbose) {
				printf($this . " constructed\n");
			}
		}

		public function __destruct() {

			if (self::$verbose) {
				printf($this . " destructed\n");
			}
		}

		public function __toString() {

			if (self::$verbose) {
				return ($ret = sprintf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, $this->_color )",
					$this->_x, $this->_y, $this->_z, $this->_w));
			}
			else {
				return ($ret = sprintf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f )",
					$this->_x, $this->_y, $this->_z, $this->_w) );
			}
		}

		public function getX() {
			return $this->_x;
		}

		public function getY() {
			return $this->_y;
		}

		public function getZ() {
			return $this->_z;
		}

		public function getW() {
			return $this->_w;
		}

		public function getColor() {
			return $this->_color;
		}

		public function setX($x) {
			$this->_x = $x;
		}

		public function setY($y) {
			$this->_y = $y;
		}

		public function setZ($z) {
			$this->_z = $z;
		}

		public function setW($w) {
			$this->_w = $w;
		}

		public function setColor($color) {
			$this->_color = $color;
		}

		public function __get($attr) {

			if ($attr == '_x') {
				return ($this->getX());
			}
			else if ($attr == '_y') {
				return ($this->getY());
			}
			else if ($attr == '_z') {
				return ($this->getZ());
			}
			else if ($attr == '_w') {
				return ($this->getW());
			}
			else if ($attr == '_color') {
				return ($this->getColor());
			}
		}

		public function __set($attr, $value) {

			if ($attr == '_x') {
				$this->setX($value);
			}
			else if ($attr == '_y') {
				$this->setY($value);
			}
			else if ($attr == '_z') {
				$this->setZ($value);
			}
			else if ($attr == '_w') {
				$this->setW($value);
			}
			else if ($attr == '_color') {
				$this->setColor($value);
			}
		}
	}
?>
