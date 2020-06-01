//importing the required modules
var express = require('express');
var app = express();
var handlebars = require('express-handlebars').create({ defaultLayout: 'main' });
var bodyParser = require('body-parser');
var mysql = require('mysql');

//setting connection on port and create connection pool
app.set('view engine', 'handlebars');
app.set('port', 19952);
app.engine('handlebars', handlebars.engine);
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use(express.static("public"));
//http://eecs.oregonstate.edu/ecampus-video/CS290/core-content/node-mysql/using-server-sql.html
var pool = mysql.createPool({
  connectionLimit: 10,
  host  : 'classmysql.engr.oregonstate.edu',
  user  : 'cs290_saradik',
  password: '0846',
  database: 'cs290_saradik'
});
module.exports.pool = pool;
//function given to us to create a new table
app.get('/reset-table',function(req,res,next){
    var context = {};
    pool.query("DROP TABLE IF EXISTS workouts", function(err){
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
        return;
      })
    });
  });
//render main page
app.get('/',function(req,res,next){
  var context = {};
  pool.query('SELECT * FROM workouts', function(err, rows, fields){

    if(err){
      next(err);
      return;
    }
    context.results = rows;
    res.render('home', context);
    return;
  });
});
//send mysql table data
app.get('/view',function(req,res,next){
  var context = {};
  pool.query('SELECT * FROM workouts', function(err, rows, fields){
    if(err){
      next(err);
      return;
    }
    context.results = rows;
    res.send(context);
    return;
  });
});
//insert data into table from get query
app.get('/insert',function(req,res,next){
  var context = {};
  pool.query("INSERT INTO workouts (`name`, `reps`, `weight`, `date`, `lbs`) VALUES (?, ?, ?, ?, ?)",
  [req.query.name,
  req.query.reps,
  req.query.weight,
  req.query.date,
  req.query.units], function(err){
    if(err){
      next(err);
      return;
    }
    pool.query('SELECT * FROM workouts', function(err, rows, fields){
      if(err){
        next(err);
        return;
      }
      context.results = rows;
      res.send(context);
      return;
    });
  });
});
//delete data from table giver get query id
app.get('/delete',function(req,res,next){
  var context = {};
  pool.query("DELETE FROM workouts WHERE id = ?",[req.query.id], function(err, result) {
    if(err){
        next(err);
        return;
    }
    pool.query('SELECT * FROM workouts', function(err, rows, fields){
      if(err){
        next(err);
        return;
      }
      context.results = rows;
      res.send(context);
      return;
    });
  });
});

//update data at id with data from query
app.get('/update',function(req,res,next){
  var context = {};
  pool.query("SELECT * FROM workouts WHERE id=?", [req.query.id], function(err, result){
    if(err){
      next(err);
      return;
    }
    if(result.length == 1){
      var curRow = result[0];
      pool.query("UPDATE workouts SET name=?, reps=?, weight=?, date=?, lbs=? WHERE id=? ",
        [req.query.name || curRow.name,
        req.query.reps || curRow.reps,
        req.query.weight || curRow.weight,
        req.query.date || curRow.date,
        req.query.units || curRow.lbs,
        req.query.id],
        function(err){
          if(err){
            next(err);
            return;
          }
          pool.query('SELECT * FROM workouts', function(err, rows){
            if(err){
              next(err);
              return;
            }
            context.results = rows;
            res.send(context);
            return;
          });
      });
    }
  });
});
//error handling
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
//start server
app.listen(app.get('port'), function() {
    console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});
;