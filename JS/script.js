app.get('/simple-insert',function(req,res,next){
    var context = {};
    mysql.pool.query("INSERT INTO cars (`make`, `model` ) VALUES (?, ?)", [req.query.make, req.query.model], function(err, result){
      if(err){
        next(err);
        return;
      }
      context.results = "Inserted id " + result.insertId;
      res.render('home',context);
    });
  });