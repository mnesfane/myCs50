-- ok a description from the crime scene that leads me to interviews
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
--
SELECT transcript FROM interviews WHERE month = 7 AND day = 28 AND transcript like "%bakery%";
-- 1
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25;
-- +--------+---------+----------------+-----------------+---------------+-----+------+-------+-----+------+--------+----------+---------------+
-- |   id   |  name   |  phone_number  | passport_number | license_plate | id  | year | month | day | hour | minute | activity | license_plate |
-- +--------+---------+----------------+-----------------+---------------+-----+------+-------+-----+------+--------+----------+---------------+
-- | 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       | 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
-- | 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
-- | 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       | 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
-- | 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
-- | 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       | 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
-- | 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       | 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
-- | 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       | 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
-- | 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       | 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
-- +--------+---------+----------------+-----------------+---------------+-----+------+-------+-----+------+--------+----------+---------------+
-- 2
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning,
--  before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

SELECT * FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions
ON bank_accounts.account_number = atm_transactions.account_number WHERE year = 2021 AND month = 7 AND day = 28
AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street';

-- +--------+---------+----------------+-----------------+---------------+----------------+-----------+---------------+-----+----------------+------+-------+-----+----------------+------------------+--------+
-- |   id   |  name   |  phone_number  | passport_number | license_plate | account_number | person_id | creation_year | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +--------+---------+----------------+-----------------+---------------+----------------+-----------+---------------+-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | 686048    | 2010          | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       | 26013199       | 514354    | 2012          | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
-- | 458378 | Brooke  | (122) 555-4581 | 4408372428      | QX4YZN3       | 16153065       | 458378    | 2012          | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 395717 | Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       | 28296815       | 395717    | 2014          | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       | 25506511       | 396669    | 2014          | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       | 28500762       | 467400    | 2014          | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       | 76054385       | 449774    | 2015          | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       | 81061156       | 438727    | 2018          | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- +--------+---------+----------------+-----------------+---------------+----------------+-----------+---------------+-----+----------------+------+-------+-----+----------------+------------------+

-- 3
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning
-- to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

SELECT * FROM people JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = ( SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29
AND origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') ORDER BY hour,minute LIMIT 1);

-- +--------+--------+----------------+-----------------+---------------+-----------+-----------------+------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate | flight_id | passport_number | seat |
-- +--------+--------+----------------+-----------------+---------------+-----------+-----------------+------+
-- | 953679 | Doris  | (066) 555-9701 | 7214083635      | M51FA04       | 36        | 7214083635      | 2A   |
-- | 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       | 36        | 1695452385      | 3B   |
-- | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       | 36        | 5773159633      | 4A   |
-- | 651714 | Edward | (328) 555-1152 | 1540955065      | 130LD9Z       | 36        | 1540955065      | 5C   |
-- | 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       | 36        | 8294398571      | 6C   |
-- | 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       | 36        | 1988161715      | 6D   |
-- | 395717 | Kenny  | (826) 555-1652 | 9878712108      | 30G67EN       | 36        | 9878712108      | 7A   |
-- | 467400 | Luca   | (389) 555-5198 | 8496433585      | 4328GD8       | 36        | 8496433585      | 7B   |
-- +--------+--------+----------------+-----------------+---------------+-----------+-----------------+------+
SELECT * FROM people JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
-- +--------+---------+----------------+-----------------+---------------+-----+----------------+----------------+------+-------+-----+----------+
-- |   id   |  name   |  phone_number  | passport_number | license_plate | id  |     caller     |    receiver    | year | month | day | duration |
-- +--------+---------+----------------+-----------------+---------------+-----+----------------+----------------+------+-------+-----+----------+
-- | 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       | 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       |
-- | 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       | 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36       |
-- | 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       | 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
-- | 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       | 251 | (499) 555-9472 | (717) 555-1342 | 2021 | 7     | 28  | 50       |
-- | 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       | 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
-- | 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       | 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
-- | 907148 | Carina  | (031) 555-6622 | 9628244268      | Q12B3Z3       | 261 | (031) 555-6622 | (910) 555-3251 | 2021 | 7     | 28  | 38       |
-- | 395717 | Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       | 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       |
-- | 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       | 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54       |
-- +--------+---------+----------------+-----------------+---------------+-----+----------------+----------------+------+-------+-----+----------+
-- bruce my buddy
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE year = 2021 AND month = 7 AND day = 29
AND origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') ORDER BY hour,minute LIMIT 1);
-- new yoooooork
SELECT * FROM people WHERE phone_number = (
    SELECT receiver FROM phone_calls WHERE caller = '(367) 555-5533' AND year = 2021 AND month = 7 AND day = 28
);




-- SELECT * FROM airports WHERE full_name = 'Fiftyville Regional Airport';
-- --
-- SELECT * FROM flights JOIN airports  WHERE origin_airport_id = 8 AND day = 29;
-- --
-- SELECT * FROM passengers WHERE flight_id = 1;
-- --
-- SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND duration = 60;
-- --
-- SELECT * FROM people WHERE phone_number = '(031) 555-6622';
-- --
-- SELECT * FROM people WHERE phone_number = '(910) 555-3251';
-- --
-- SELECT * FROM bakery_security_logs LIMIT 1;
-- --
-- SELECT * FROM bakery_security_logs WHERE license_plate = '43V0R5D' AND month = 7 AND day = 28;