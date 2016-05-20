<?php

if (isset($_GET["s"]))
{

$conn = mysql_connect($localhost, fsr, f5r);

$s = $_GET["s"];
$r = $_GET["r"];
$date = date('"Y-M-Dd"');
//echo $s;
//echo $r;

$sql = "INSERT INTO one "."(s, r,triggerts,date) ". "VALUES('$s','$r',NOW(),CURDATE())"; 
mysql_select_db('fsr');
$retval = mysql_query( $sql, $conn);

if(! $retval )
{ die('Could not enter data: ' . mysql_error()); }

//echo "Entered data successfully\n";

mysql_close($conn);

$e = date("h:i:sa");

mail("1571548E@student.tp.edu.sg"," FT-RM1-$e !!! ","Customer Paging - Fitting RM 1 - Time $e !!!");
}
?>
