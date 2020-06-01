//Function to add a row to the html table and fill it in with the information passed to it from the SQL database table
function addRow(workout, rep, weight, date, unit, Iden){
  var table = document.getElementById("sqlTable");
  var newRow = document.createElement("tr");  //create a row 
  data = [workout, rep, weight, date, unit] //add vaues to a list
  //loop through each cell and label it accordingly
  for(var col = 0; col < 5; col++){
      var cell = document.createElement("td");
      cell.textContent = data[col];
      newRow.appendChild(cell);
  }
  //create a button to edit the data
  var editButton = document.createElement("Input")
  editButton.setAttribute("type", "button");
  editButton.setAttribute("value", "Edit Values");
  newRow.appendChild(editButton);
  table.appendChild(newRow)
  //button to delete the row
  var deleteButton = document.createElement("Input")
  deleteButton.setAttribute("type", "button");
  deleteButton.setAttribute("value", "Delete Row");
  deleteButton.setAttribute("onclick", "deleteRow(this.id)"); //when clicked calls the delete function
  deleteButton.setAttribute("id", Iden);
  newRow.appendChild(deleteButton);

  table.setAttribute("border", "1px");
}


//loads the information and add its to the table when clicked 
document.getElementById('addButton').addEventListener('click', function(event){
  var req = new XMLHttpRequest();
  var payload = "/?" + "workout="+newEntry.elements.workout.value+    
  "&reps="+newEntry.elements.reps.value+
  "&weight="+newEntry.elements.weight.value+
  "&date="+newEntry.elements.date.value+
  "&units=1";

  req.open("GET",payload, true);                 
  req.addEventListener('load', function(){                       
    if(req.status >= 200 && req.status < 400){
      var response = JSON.parse(req.responseText);       
      for(obj in response){ //for each object in the response list, add a row with the name, rep, weight, date, and units
        addRow(obj[0],obj[1],obj[2],obj[3],obj[4],obj[5]);
      }
    }
    else {
        console.log("error");
    }
  });
  req.send(payload);
  event.preventDefault();
 
})
//function to delete the row which uses a POST method and passes the id of the row to be deleted, then deletes the row from the HTML table
function deleteRow(row){
  var table = document.getElementById("sqlTable");
  var payload = "/?id=" + row.elements.id;
  req.open("POST",payload, true);                 
  req.addEventListener('load', function(){                       
    if(req.status >= 200 && req.status < 400){
      table.deleteRow(row.rowIndex);
    }
    else {
        console.log("error");
    }
  });
  req.send(param);
  event.preventDefault();
}
