SELECT
    DATEDIFF(MAX(`date`),
    MIN(`date`))
FROM
    `member_history`;
