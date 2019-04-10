<?php

class Color
{

  public $red;
  public $green;
  public $blue;
  static public $verbose = False;

  function __construct( array $data ) {
    if (array_key_exists('red', $data) && array_key_exists('green', $data) && array_key_exists('blue', $data)) {
      $this->red = (int)$data['red'];
      $this->green = (int)$data['green'];
      $this->blue = (int)$data['blue'];
    }
    else if (array_key_exists('rgb', $data)) {
      $this->red = (int)(($data['rgb'] & 0x00ff0000) >> 16);
      $this->green = (int)(($data['rgb'] & 0x0000ff00) >> 8);
      $this->blue = (int)($data['rgb'] & 0x000000ff);
    }
    if (self::$verbose)
      print($this . " constructed." . PHP_EOL);
    return ;
  }

  function __destruct() {
    if (self::$verbose)
      print($this . " destructed." . PHP_EOL);
    return ;
  }

  function __toString() {
    return sprintf ("Color( red: % 3d, green: % 3d, blue: % 3d )", $this->red, $this->green, $this->blue);
  }

  static function doc() {
    $doc = file_get_contents("Color.doc.txt");
    print($doc);
  }

  public function add($color) {
    $new = new Color([
      'red' => $color->red + $this->red,
      'green' => $color->green + $this->green,
      'blue' => $color->blue + $this->blue
    ]);
    return $new;
  }

  public function sub($color) {
    $new = new Color([
        'red' => $this->red - $color->red,
      'green' => $this->green - $color->green,
      'blue' => $this->blue - $color->blue
    ]);
    return $new;
  }

  public function mult($mult) {
    $new = new Color([
      'red' => $this->red * $mult,
      'green' => $this->green * $mult,
      'blue' => $this->blue * $mult
    ]);
    return $new;
  }

}

?>
