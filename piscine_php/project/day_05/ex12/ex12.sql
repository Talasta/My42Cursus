SELECT
    last_name,
    first_name
FROM
    user_card
WHERE
    INSTR(last_name, '-') OR INSTR(first_name, '-')
ORDER BY
    last_name ASC,
    first_name ASC;
