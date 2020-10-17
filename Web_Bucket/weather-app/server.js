const express = require('express');
const path = require('path');

const app = express();
app.use(express.static('./dist/weather-app'));

app.get('/', function(req, res) {
  res.sendFile('index.html', {root: 'dist/weather-app'});
});

app.listen(process.env.PORT || 8080);
