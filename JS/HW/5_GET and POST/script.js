var express = require('express');

var app = express();
var handlebars = require('express-handlebars').create({ defaultLayout: 'main' });

var bodyParser = require('body-parser');

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 3000);
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.get("/", function(req, res) {
    var parameters = [];
    for (var p in req.query) {
        parameters.push({ "name": p, "value": req.query[p] })
    }
    var data = {};
    data.params = parameters;
    res.render("get", data);
});

app.post('/', function(req, res) {
    var parameters = [];
    for (var p in req.query) {
        parameters.push({ "name": p, "value": req.query[p] })
    }
    var parameters1 = [];
    for (var p in req.body) {
        parameters1.push({ "name": p, "value": req.body[p] })
    }
    var data = {};
    data.params = parameters;
    data.bodyparams = parameters1;
    res.render('post', data);
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