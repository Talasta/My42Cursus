SELECT
    COUNT(DISTINCT id_film)
FROM
    `member_history`
WHERE
    `date` > '2006-10-30' AND `date` < '2007-07-27' OR DATE_FORMAT(`date`, '%m-%e') = '12-24';
