<?php

class Jaime extends Lannister
{

  public function sleepWith( $arg ) {
    parent::sleepWith($arg);
    if (is_subclass_of($arg, get_parent_class($this)) && get_class($arg) == "Cersei") {
      print("With pleasure, but only in a tower in Winterfell, then." . PHP_EOL);
    } else if (is_subclass_of($arg, get_parent_class($this)) && get_class($arg) == "Tyrion") {
      print("Not even if I'm drunk !" . PHP_EOL);
    }
  }

}


?>
