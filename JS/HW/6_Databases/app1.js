//importing the required modules
var express = require('express');
var app = express();
var handlebars = require('express-handlebars').create({ defaultLayout: 'main' });
var bodyParser = require('body-parser');
var mysql = require('mysql'); 

//setting connection on port and create connection pool
app.set('view engine', 'handlebars');
app.set('port', 3000);
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.engine('handlebars', handlebars.engine);
//http://eecs.oregonstate.edu/ecampus-video/CS290/core-content/node-mysql/using-server-sql.html
var pool = mysql.createPool({
    connectionLimit: 10,
    host  : 'localhost',
    user  : 'root',
    password: 'admin',
    database: 'student'
  });

//function given to us to create a new table
app.get('/reset-table',function(req,res,next){
    var context = {};
    pool.query("DROP TABLE IF EXISTS workouts", function(err){ //replace your connection pool with the your variable containing the connection pool
      var createString = "CREATE TABLE workouts("+
      "id INT PRIMARY KEY AUTO_INCREMENT,"+
      "name VARCHAR(255) NOT NULL,"+
      "reps INT,"+
      "weight INT,"+
      "date DATE,"+
      "lbs BOOLEAN)";
      pool.query(createString, function(err){
        context.results = "Table reset";
        res.send(context);
      })
    });
  });


//main route to send data from the database table
app.get("/", function(req, res, next) {
  if(req.query.length == undefined){
    pool.query('SELECT * FROM workouts', function(err,rows){
      if(err){
        next(err);
        return;
        }
      var context = {};
      context.results = JSON.stringify(rows);
      res.render('home', context);
    });
  }
  else if(req.query.length == 1){
    pool.query("DELETE FROM workouts WHERE id = ?",[req.query.id], function(err, result) {
      if(err){
          next(err);
          return;
      }
      context.results = JSON.stringify(rows);
      res.send(context);
    });
  }
  else{
    pool.query("INSERT INTO workouts (`name`, `reps`, `weight`, `date`, `lbs`) VALUES (?, ?, ?, ?, ?)",
    [req.query.workout,              
    req.query.reps, 
    req.query.weight, 
    req.query.date, 
    req.query.units], function(err, result){
      if(err){
        next(err);
        return;
      }         
      context.results = JSON.stringify(rows);
      res.send(context);
      });
  }
});


app.post('/',function(req,res,next){
  mysql.pool.query("SELECT * FROM workouts WHERE id=?", [req.query.id], function(err, result){
    if(err){
      next(err);
      return;
    }
    if(result.length == 1){
      var curRow = result[0];
      mysql.pool.query("UPDATE workouts SET name=?, reps=?, weight=? date=? lbs=? WHERE id=? ",
        [req.query.name || curRow.name,
        req.query.reps || curRow.reps,
        req.query.weight || curRow.weight,
        req.query.date || curRow.date,
        req.query.lbs || curRow.lbs,
        req.query.id],
        function(err, result){
        if(err){
          next(err);
          return;
        }
        context.results = JSON.stringify(rows);
        res.send(context);
      });
    }
  });
});

app.use(function(req, res) {
    res.status(404);
    res.render('404');
});

app.use(function(err, req, res, next) {
    console.error(err.stack);
    res.type('plain/text');
    res.status(500);
    res.render('500');
});

app.listen(app.get('port'), function() {
    console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});