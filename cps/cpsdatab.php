<?php
    $dbhost="localhost";
    $dblogin="fsr";
    $dbpwd="f5r";
    $dbname="fsr";
       
    $db =  mysql_connect($dbhost,$dblogin,$dbpwd);
    mysql_select_db($dbname);    
	
    //$day = date('d');
    //$month = date('m');
    //$lastMonth = (string)($month-1);	
    //$lastMonth = strlen($month - 1) == 1? '0'.$lastMonth : $lastMonth;
    
    $SQLString = "SELECT count(r) AS count, date FROM one GROUP BY date ORDER BY date";		
										
    $result = mysql_query($SQLString);    
    $num = mysql_num_rows($result);   

# set heading	
    $data[0] = array('day','count');		
    for ($i=1; $i<($num+1); $i++)
    {
        $data[$i] = array(substr(mysql_result($result, $i-1, "date"), 0, 10),
			(int) mysql_result($result, $i-1, "count"));
    }	
    echo json_encode($data);
    mysql_close($db);
?>
