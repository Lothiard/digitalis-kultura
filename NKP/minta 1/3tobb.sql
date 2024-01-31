SELECT csapat.varos, COUNT(csapat.id) as db
FROM csapat
GROUP BY 1
HAVING db > 1;