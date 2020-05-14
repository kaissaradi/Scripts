var apiKey = "&appid=d1b0620438316662aec4d0a6b1ce8f39";
document.addEventListener('DOMContentLoaded', bindButtons);

function bindButtons(){
  document.getElementById('submitWeather').addEventListener('click', function(event){
    var req = new XMLHttpRequest();
    var zip = document.getElementById("zip").value;
    var countrycode = document.getElementById("countrycode").value;
    var payload = "http://api.openweathermap.org/data/2.5/weather?zip=" + zip + "," + countrycode + apiKey;
    req.open("GET", payload, true);
    req.addEventListener('load', function() {
      if (req.status >= 200 && req.status < 400) {
        var response = JSON.parse(req.responseText);
        document.getElementById("currCity").textContent = response.name;
			  document.getElementById("temp").textContent = response.main.temp;
			  document.getElementById("hum").textContent = response.main.humidity;
      }else{
        document.getElementById("currCity").textContent = "Error!";
			  document.getElementById("temp").textContent = "Error!";
			  document.getElementById("hum").textContent = "Error!";
      }
    });
    req.send();
    event.preventDefault();
  })
}

//code template from week 6 notes JavaScript and HTTP (also forms)