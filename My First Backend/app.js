const express = require("express");
const app = express();

app.listen(8080);
app.get("/", (request, response) => {
    songs = ["Ac-cent-tchu-ate the Positive", "Accidents Will Happen", "Adeste Fideles", "Ad-Lib Blues", "An Affair to Remember (Our Love Affair)", "After You've Gone", "Ain't She Sweet", "Ain't Cha Ever Comin' Back?", "Air For English Horn", "Alice Blue Gown", "All Alone", "All By Myself", "All I Do Is Dream of You", "All I Need is the Girl", "All My Tomorrows", "All of Me", "All of You", "All or Nothing at All", "All the Way Home", "All the Way"]
    num=Math.floor (Math.random()*21);

    return response.send (songs[num]);
})

app.get("/birth_date", (request, response) => {
    birth_date = ("December 12, 1915")

    return response.send (birth_date);
})

app.get("/birth_city", (request, response) => {
    birth_city = ("Hoboken, New Jersey")

    return response.send (birth_city);
})

app.get("/wives", (request, response) => {
    wives = ("Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Marx")

    return response.send (wives);
})

app.get("/picture", (request, response) => {
    picture = ("https://en.wikipedia.org/wiki/Frank_Sinatra#/media/File:Frank_Sinatra2,_Pal_Joey.jpg")

    return response.redirect (picture);
})

app.get("/public", (request, response) => {
    public = ("Everybody can see this page")

    return response.send (public);
})

app.get('/protected', (req, res) => {
    const auth_header = req.headers.authorization;

   if (!auth_header) {
       res.status(401);
       res.end("Not authorized");
   }

   let auth = Buffer.from(auth_header.split(' ')[1], 'base64').toString();
   const username = auth.substring(0, auth.indexOf(":"));
   const password = auth.substring(auth.indexOf(":")+1);

   if (username === 'admin' && password === 'admin') {
       res.write("Welcome, authenticated client\n");
   } else {
       res.status(401);
       res.write("Not authorized\n");
   }
   res.end();
});