UPDATE shows SET title = "Adventure Time" WHERE title LIKE "adventure time";
SELECT * FROM id WHERE id = 116;
UPDATE shows SET title = "Arrow" WHERE title LIKE "arrow";
UPDATE shows SET title = "Avatar: The Last Airbender" WHERE title LIKE "Avatar The Last Airbender";
...
SELECT * FROM shows WHERE title LIKE "b%";
UPDATE shows SET title = "Brooklyn Nine-Nine" WHERE title LIKE "B99";
UPDATE shows SET title = "Brooklyn Nine-Nine" WHERE title LIKE "brooklyn%";
SELECT * FROM shows WHERE title LIKE "g%";
UPDATE shows SET title = "Game of Thrones" WHERE title LIKE "GoT";
SELECT * FROM shows WHERE title LIKE "g%";
UPDATE shows SET title = "Grey’s Anatomy" WHERE title LIKE "Grey%";
SELECT * FROM shows WHERE title LIKE "i%";
UPDATE shows SET title = "It’s Always Sunny in Philadelphia" WHERE title LIKE "%Philadelphia";
SELECT * FROM shows WHERE title LIKE "p%";
UPDATE shows SET title = "Parks and Recreation" WHERE title LIKE "Parks and Rec%";
SELECT * FROM shows WHERE title LIKE "o%";
UPDATE shows SET title = "The Office" WHERE title LIKE "%Office";

SELECT * FROM shows ORDER BY title;
