//Function to create a table of given rows and columns and add it to the page body
function createTable(rows, cols){
    //create the table and body
    var table = document.createElement("table");  
    var tableBody = document.createElement("tbody");   
    //loop through each cell and label it accordingly
    for(var row = 0; row < rows; row++){//create each row and add each cell to the row
        var tableRow = document.createElement("tr"); 
        for(var col = 0; col < cols; col++){
            if(row == 0){//create header row
                var headerCell = document.createElement("th");
                headerCell.appendChild(document.createTextNode("Header " + (col + 1)));
                tableRow.appendChild(headerCell);    //add header cell to the current row in the table
            }else{//add regualr cells to the table with their position as text
                var cell = document.createElement("td");
                cell.appendChild(document.createTextNode((row) + ", " + (col + 1)));
                tableRow.appendChild(cell);
            }
        }
        tableBody.appendChild(tableRow);        //add each row to the table
    }
    table.appendChild(tableBody);
    table.setAttribute("border", "1px");
    document.body.appendChild(table); //add the table to the page body
}

//Function to create Buttons containing the text passed to the function and add it to the page body
function createButtons(text){
    //create each button and add it to the page body
    var button = document.createElement("button");
    button.id = text;   //set button id to text passed
    button.appendChild(document.createTextNode(text));
    document.body.appendChild(button); 
}

//Function to move spaces based on the direction passed to it (1 = up, 2= down, 3 = right, 4= left)
function changeSpace(directionInt, rows, cols){
    selectedCell = document.getElementById("selected");
    var colIndex = selectedCell.cellIndex;  //save column index 
    //check if the selected cell has is at the edge of the table and change cells
    if(directionInt == 1){
        if(selectedCell.parentNode.rowIndex <= 1){               
            return;
        } 
        //deselect cell
        selectedCell.style.borderWidth = "1px";    
        selectedCell.removeAttribute("id"); 
        //change selected cell to first cell of row above  
        selectedCell = selectedCell.parentNode;
        selectedCell = selectedCell.previousSibling;
        selectedCell= selectedCell.firstChild;
        //change selected cell to cell at column index
        for(var i = 0; i < colIndex; i++){
            selectedCell = selectedCell.nextSibling;
        }                                         
    }
    if(directionInt == 2){
        if(selectedCell.parentNode.rowIndex >= (rows - 1)){
            return;
        }
        //deselect cell
        selectedCell.style.borderWidth = "1px";    
        selectedCell.removeAttribute("id"); 
        //change selected cell to first cell of row below
        selectedCell = selectedCell.parentNode;  
        selectedCell = selectedCell.nextSibling;
        selectedCell= selectedCell.firstChild;
        for(var i = 0; i < colIndex; i++){
            selectedCell = selectedCell.nextSibling;
        } 
    }
    if(directionInt == 3){
        if(selectedCell.cellIndex >= (cols - 1)){
            return;
        }
        //deselect cell
        selectedCell.style.borderWidth = "1px";    
        selectedCell.removeAttribute("id"); 
        //change cell 
        selectedCell = selectedCell.nextSibling;
    }
    if(directionInt ==4){
        if(selectedCell.cellIndex <= 0){
            return;
        } 
        //deselect cell
        selectedCell.style.borderWidth = "1px";    
        selectedCell.removeAttribute("id"); 
        //change  cell
        selectedCell = selectedCell.previousSibling;
    }
    //select cell  
    selectedCell.style.borderWidth = "5px";    
    selectedCell.id = "selected"; 
}

//call the functions to create the table and buttons
createTable(4,4);
createButtons("Up");
createButtons("Down");
createButtons("Right");
createButtons("Left");
createButtons("Mark Cell");

//select the first cell in the table
var selectedCell = document.getElementsByTagName("td")[0];
selectedCell.id = "selected"; 
selectedCell.style.borderWidth = "5px"; 

//add event listeners to the buttons to call  the appropriate function on click
document.getElementById("Up").addEventListener("click", function(){changeSpace(1,4,4)}); 
document.getElementById("Down").addEventListener("click", function(){changeSpace(2,4,4)});
document.getElementById("Right").addEventListener("click", function(){changeSpace(3,4,4)});
document.getElementById("Left").addEventListener("click", function(){changeSpace(4,4,4)});
document.getElementById("Mark Cell").addEventListener("click", function(){selectedCell.style.backgroundColor = "#ffff33";});