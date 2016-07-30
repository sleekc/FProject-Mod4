Folder -> AWS-Debian ->contain resouces on setting up the required services

Folder -> Arduino-Nodemcu-Fritzing Img -> contain Arduino + FSR Sensor, Nodemcu + LED wiring diagram.

Folder -> cps ->contain php script that is in AWS

1)cps.php->The script connect,and insert the value into the database, send email, mqtt publish to topic ftrm with value 1

2)cpsdata.php->Script the do a sql query, count all the reading in a day, prepare the return data in json for google chart.

3)cpsdashb.html/index.html/indexl.html->a script that read the json data from cpsdata.php and draw on a line or bar chart.

4)phpMQTT.php -> MQTT script require by cps.php to publish to mqtt server. Source: https://github.com/bluerhinos/phpMQTT

Folder -> mqtt_esp8266-240516-nodemcu-client1/2 -> script to subscript to topic ftrm and LED on when value 1 is received.

Folder -> yun-fsr-led-jcs-simple -> contain yun-fsr-led-jcs-simple.ino (Arduino scripts to read/send sensor data to AWS and trigger JCS system in TP via 5v Relay)
