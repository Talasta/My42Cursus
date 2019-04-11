<?php

class Tyrion extends Lannister
{

  public function sleepWith( $arg ) {
    parent::sleepWith($arg);
    if (is_subclass_of($arg, get_parent_class($this))) {
      print("Not even if I'm drunk !" . PHP_EOL);
    }
  }

}


?>
