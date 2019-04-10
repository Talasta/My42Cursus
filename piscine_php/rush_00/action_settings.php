<?php
session_start();
include_once("database.php");

if (!isset($_SESSION['login_connected']))
{
  header("Location: index.php");
  die();
}

if (isset($_POST['type']))
{
  if ($_POST['type'] == 'Change password' && isset($_POST['p_password']) && $_POST['p_password'] && isset($_POST['p_new_password']) && $_POST['p_new_password'])
  {
    $pass = ft_get_password_from_login($_SESSION['login_connected']);
    $hash = hash("md5", $_POST['p_password']);
    if ($pass[0][2] == $hash && $_POST['p_new_password'] == $_POST['p_s_new_password'])
    {
      $hash = hash("md5", $_POST['p_new_password']);
      ft_change_password($_SESSION['login_connected'], $hash);
    }
  }

  if ($_POST['type'] == 'Change login' && isset($_POST['l_password']) && $_POST['l_password'] && isset($_POST['l_new_login']) && $_POST['l_new_login'])
  {
    $pass = ft_get_password_from_login($_SESSION['login_connected']);
    $hash = hash("md5", $_POST['l_password']);
    if ($pass[0][2] == $hash && !ft_get_user($_POST['l_new_login']))
    {
      ft_change_login($_POST['l_new_login'], $_SESSION['login_connected']);
    }
  }

  if ($_POST['type'] == 'Delete user' && $_POST['d_password'])
  {
    $pass = ft_get_password_from_login($_SESSION['login_connected']);
    $hash = hash("md5", $_POST['d_password']);
    if ($pass[0][2] == $hash)
    {
      ft_delete_login($_SESSION['login_connected']);
      unset($_SESSION['login_connected']);
      unset($_SESSION['admin']);
      header("Location: index.php");
      die();
    }
  }
}
header("Location: index.php?setting=");
?>
