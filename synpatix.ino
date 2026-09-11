#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>

const char index_html [] PROGMEM = R"teqsti(<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>SynaptiX</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Orbitron:wght@400..900&display=swap" rel="stylesheet">
</head>
<style>
    html,
    body {
        width: 100%;
        height: 100%;
        padding: 0px;
        margin: 0px;
    }

    body {
        display: flex;
        flex-direction: column;
        justify-content: flex-start;
        align-items: center;
        gap: 30px;
        background-image: url("https://d9-wret.s3.us-west-2.amazonaws.com/assets/palladium/production/s3fs-public/styles/full_width/public/thumbnails/image/fig1-dnb_united_states_sml.jpg?itok=8I3a7OC2");
        overflow-y: auto;
    }

    #title_id {
        font-family: "Orbitron", sans-serif;
        font-size: 80px;
        flex-direction: row;
        display: flex;
        justify-content: space-around;
        align-items: center;
        gap: 50px;
        border-radius: 20px;
        border-style: none;
        transition: all 0.6s;
        color: rgba(137, 43, 226, 0.734);
        background-color: white;
        user-select: none;
    }

    #title_id:hover {
        background-color: rgba(137, 43, 226, 0.734);
        color: white;
        box-shadow: 0 0 5px 10px rgba(0, 0, 255, 0.888);
        border-style: solid;
        border-width: 3px;
    }

    #flag_id {
        object-fit: cover;
        height: 80px;
        border-radius: 5px;
        transition: all 0.6s;
        cursor: pointer;
    }

    #flag_id:hover {
        box-shadow: 0 0 10px 5px rgba(0, 0, 0, 0.684);
    }

    #name_id {
        transition: all 0.6s;
        border-radius: 30px;
        cursor: pointer;
    }

    #name_id:hover {
        box-shadow: 0 0 10px 5px rgba(0, 0, 0, 0.684);
    }

    #contact_id {
        font-size: 40px;
        border-radius: 20px;
        padding: 10px;
        cursor: pointer;
        transition: all 0.6s;
        text-decoration: none;
        color: inherit;
    }

    #contact_id:hover {
        box-shadow: 0 0 10px 5px rgba(0, 0, 0, 0.684);
        color: white;
    }

    main {
        flex: 1;
        width: 100%;
        max-width: 1200px;
        border-radius: 20px;
        display: flex;
        flex-direction: column;
        gap: 20px;
        padding-bottom: 30px;
    }

    #top_bar {
        display: flex;
        flex-direction: row;
        justify-content: space-around;
        align-items: center;
        border-style: solid;
        box-sizing: border-box;
        border-radius: 30px;
        border-color: gray;
        background-color: aqua;
        padding: 10px;
        border-width: 5px;
    }

    #logo_id {
        width: 100px;
        object-fit: cover;
        object-position: center;
        border-radius: 30px;
    }

    img {
        transition: all 0.6s;
    }

    img:hover {
        box-shadow: 0 0 5px 10px rgba(0, 0, 0, 0.684);
    }

    span:hover {
        box-shadow: 0 0 5px 10px rgba(0, 0, 0, 0.684);
    }

    content {
        display: flex;
        flex-direction: row;
        flex-wrap: wrap;
        justify-content: center;
        gap: 20px;
    }

    article {
        display: flex;
        flex-direction: column;
        justify-content: center;
        gap: 10px;
        align-items: center;
        background: rgba(255, 255, 255, 0.8);
        padding: 15px;
        border-radius: 15px;
    }

    .sensor_id {
        color: violet;
        border-radius: 10px;
        padding: 10px;
        font-family: "Orbitron";
        font-size: 18px;
        transition: all 0.6s;
        background-color: azure;
        text-align: center;
    }
</style>

<body>
    <span id="title_id">
        <img src="https://cdn.britannica.com/33/4833-050-F6E415FE/Flag-United-States-of-America.jpg?w=1000"
            id="flag_id">
        <span id="name_id">SynaptiX</span>
        <a href="https://www.pinterest.com/pin/831758624979130183" target="_blank" id="contact_id">
            contact the elder
        </a>
    </span>
    <main>
        <header>
            <div id="top_bar">
                <img src="https://scontent.ftbs6-2.fna.fbcdn.net/v/t39.30808-1/739917770_2272856050153431_7604518042153043871_n.jpg?stp=dst-jpg_tt6&cstp=mx1254x1254&ctp=s200x200&_nc_cat=106&ccb=1-7&_nc_sid=2d3e12&_nc_ohc=H0aERnv97RMQ7kNvwFtb2fI&_nc_oc=AdrVYyTy3iCO1kgEfXFRplRUCkShuKpVCOsmECwpWAkyOYqWD3IAe_M-iRpqgtw0_dA&_nc_zt=24&_nc_ht=scontent.ftbs6-2.fna&_nc_gid=lqs8eOu8muKMHYJptRHhBQ&_nc_ss=7b2a8&oh=00_AQLF38B_iWH_-om-EC8iylkEsXJXHoCbgX5nO19BzDasvg&oe=6AA08F9F"
                    id="logo_id">
                <span
                    style="font-family: 'Orbitron'; font-size: 35px; user-select: none; cursor: pointer; color: black; border-radius: 50px; padding: 10px; border-style: solid; border-width: 5px; border-color: violet; transition: all 0.6s; text-align: center;">
                    Force sensitive resistor readings
                </span>
            </div>
        </header>
        <content>
            <article>
                <span class="sensor_id">First Fsr Readings</span>
                <span id="first_sensor_id" class="sensor_id">2023</span>
            </article>
            <article>
                <span class="sensor_id">Second Fsr Readings</span>
                <span id="second_sensor_id" class="sensor_id">3910</span>
            </article>
            <article>
                <span class="sensor_id">Third Fsr Readings</span>
                <span id="third_sensor_id" class="sensor_id">987</span>
            </article>
            <article>
                <span class="sensor_id">Fourth Fsr Readings</span>
                <span id="fourth_sensor_id" class="sensor_id">2345</span>
            </article>
            <article>
                <span class="sensor_id">Fifth Fsr Readings</span>
                <span id="fifth_sensor_id" class="sensor_id">3215</span>
            </article>
            <article>
                <span class="sensor_id">Sixth Fsr Readings</span>
                <span id="sixth_sensor_id" class="sensor_id">1543</span>
            </article>
            <article>
                <span class="sensor_id">Seventh Fsr Readings</span>
                <span id="seventh_sensor_id" class="sensor_id">1000</span>
            </article>
            <article>
                <span class="sensor_id">Eighth Fsr Readings</span>
                <span id="eighth_sensor_id" class="sensor_id">2000</span>
            </article>
        </content>
    </main>

    <script>
        function updateSensors() {
            fetch('/data')
                .then(response => response.json())
                .then(data => {
                    document.getElementById('first_sensor_id').textContent = data[0];
                    document.getElementById('second_sensor_id').textContent = data[1];
                    document.getElementById('third_sensor_id').textContent = data[2];
                    document.getElementById('fourth_sensor_id').textContent = data[3];
                    document.getElementById('fifth_sensor_id').textContent = data[4];
                    document.getElementById('sixth_sensor_id').textContent = data[5];
                    document.getElementById('seventh_sensor_id').textContent = data[6];
                    document.getElementById('eighth_sensor_id').textContent = data[7];
                })
                .catch(error => console.error('Error fetching sensor data:', error));
        }
        setInterval(updateSensors, 100);
    </script>
</body>
</html>)teqsti";

WebServer serveri(80);
const char* saxeli = "GITA_PREMIUM";
const char* paroli = "Premium12.";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(saxeli, paroli);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("East Asia Rocks!!!");
    delay(500);
  }
  delay(1000);
  MDNS.begin("synaptix");
  Serial.println(WiFi.localIP());
  
  serveri.on("/", HTTP_GET, [](){
    serveri.send(200, "text/html", index_html);
  });
  
  serveri.on("/data", HTTP_GET, [](){
    int fsrArray[8] = {
        analogRead(1),
        analogRead(2),
        analogRead(3),
        analogRead(4),
        analogRead(5),
        analogRead(6),
        analogRead(7),
        analogRead(8),
    };
    String jsonStr = "[";
    for(int i = 0; i < 8; i++) {
      jsonStr += String(fsrArray[i]);
      if(i < 7) jsonStr += ",";
    }
    jsonStr += "]";
    serveri.send(200, "application/json", jsonStr);
  });
  
  serveri.begin();
}
unsigned long lastSerialPrint = 0;
void loop() {
    serveri.handleClient();
    if (millis() - lastSerialPrint > 1000) {
        lastSerialPrint = millis();
        for (int i = 1; i <= 8; i++) {
            Serial.print("Pin ");
            Serial.print(i);
            Serial.print(": ");
            Serial.println(analogRead(i));
        }
        Serial.println("-------------------");
    }
}
