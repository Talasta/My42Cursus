<?php

class Lannister
{

  public function sleepWith( $arg ) {
    if (get_parent_class($arg) != get_parent_class($this)) {
      print("Let's do this." . PHP_EOL);
    }
  }

}


?>
