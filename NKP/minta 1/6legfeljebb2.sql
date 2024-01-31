SELECT csapat.nev
FROM csapat, meccs
WHERE csapat.id = meccs.magyar
GROUP BY 1
HAVING MAX(meccs.lott) <= 2;

-- vagy

SELECT DISTINCT csapat.nev
FROM csapat, meccs
WHERE csapat.id = meccs.magyar
AND csapat.nev NOT IN 
    (SELECT csapat.nev
    FROM csapat, meccs
    WHERE csapat.id = meccs.magyar
    AND meccs.lott > 2);