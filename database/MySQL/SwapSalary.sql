UPDATE
    Salary
SET
    /* In the case where 'sex' is m, set sex to f
    if not the case set 'sex' to f. This makes m -> f and f -> m */
    sex = CASE sex
        WHEN 'm' THEN 'f'
        ELSE 'm'
END;