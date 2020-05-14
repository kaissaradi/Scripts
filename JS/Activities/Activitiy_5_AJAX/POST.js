document.addEventListener('DOMContentLoaded', bindButtons);

function bindButtons(){
  //setup even listener for submit and set payload
  document.getElementById('submitWeather').addEventListener('click', function(event){
  var req = new XMLHttpRequest();
  var payload = {"city": null, "zip": null}
  payload.zip = document.getElementById("zip").value;
  payload.city = document.getElementById("city").value;
    //make request
  req.open('POST','http://httpbin.org/post', true);
  req.setRequestHeader('Content-Type', 'application/json');
  req.addEventListener('load',function(){
    if(req.status >= 200 && req.status < 400){
      var response = JSON.parse(req.responseText);
      response = JSON.parse(response.data);
      document.getElementById('currCity').textContent = response.city;
      document.getElementById('currZip').textContent = response.zip;
    } else {
      document.getElementById('currCity').textContent = "Error";
      document.getElementById('currZip').textContent = "Error!";
    }});
  req.send(JSON.stringify(payload));
  event.preventDefault();
  })
}

//code template from week 6 notes JavaScript and HTTP (also forms)