var apiKey = "&appid=d1b0620438316662aec4d0a6b1ce8f39";
document.addEventListener('DOMContentLoaded', bindButtons);

function calctemp(celcius){
    //(0°C × 9/5) + 32 = 32°F
    faren = parseInt((celcius * (9/5)) + 32);
    return faren;
}

function wind(speed){
    return (parseInt(speed * 2.237));
}

function snow(meters){
    return (parseInt(meters * 39.37));
}

function bindButtons() {
    document.getElementById('submitWeather').addEventListener('click', function(event) {
        var req = new XMLHttpRequest();
        var zip = document.getElementById("weather-form").value;
        var payload = "https://api.weather.gov/stations/" + zip + "/observations/latest";
        req.open("GET", payload, true);
        req.addEventListener('load', function() {
            if (req.status >= 200 && req.status < 400) {
                var response = JSON.parse(req.responseText);
                document.getElementById("temp").textContent = calctemp(response.properties.temperature.value) + " °F";
                document.getElementById("desc").textContent = response.properties.textDescription;
                document.getElementById("wind").textContent = "Wind Gusts: " + wind(response.properties.windGust.value) + " MPH";
                document.getElementById("snow").textContent = wind(response.properties.precipitationLast3Hours.value) + "''";
                console.log(JSON.parse(response.properties.presentWeather));

            } else {
                document.getElementById("currCity").textContent = "Error!";
                document.getElementById("temp").textContent = "Error!";
                document.getElementById("hum").textContent = "Error!";
            }
        });
        req.send();
        event.preventDefault();
    })
}