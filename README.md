FProject

Folder -> Arduino-Fritzing Img contain Arduino + FSR Sensor wiring diagram

Folder -> cps contain php script that is in AWS

1)cps.php->The script connect,and insert the value into the database.

2)cpsdata.php->Script the do a sql query, count all the reading in a day, prepare the return data in json for google chart.

3)cpsdashb.html/index.html/indexl.html->a script that read the json data from cpsdata.php and draw on a line or bar chart.

Folder -> yun-fsr-led-simple contain yun-fsr-led-simple.ino (Arduino to read sensor data and send the reading to AWS debian)
