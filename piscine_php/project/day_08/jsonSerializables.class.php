<?php

interface jsonSerializables
{
  public function jsonSerialize();
  public static function jsonUnserialize( $jsonString );

}


 ?>
