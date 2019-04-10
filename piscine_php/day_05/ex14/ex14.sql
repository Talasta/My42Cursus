SELECT
    floor_number AS FLOOR,
    SUM(nb_seats) AS seats
FROM
    `cinema`
GROUP BY
    floor_number
ORDER BY
    seats
DESC;
