# FProject

Physical Script - yun-fsr-led-simple.ino (arduino to sense data and send the reading to AWS debian instants)

AWS Script
1) cps.php -> The script connect,and insert the value into the database,mqtt publish to topic ftrm

2) cpsdata.php -> Script the do a sql query (count all the reading in a day, and prepare the return data in json for google chart.

3) cpsdashb.html -> a script that read the json data from cpsdata.php and draw on a line or bar chart.
