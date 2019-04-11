INSERT INTO ft_table (login, `group`, creation_date)
SELECT user_card.last_name AS login, 'other' AS `group`, user_card.birthdate AS creation_date
FROM sql42.user_card
WHERE INSTR(user_card.last_name, 'a')
AND CHAR_LENGTH(user_card.last_name) < 9
ORDER BY last_name ASC LIMIT 10;
