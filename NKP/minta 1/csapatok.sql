SELECT csapat.nev, csapat.varos
FROM csapat
WHERE csapat.nemzet = "magyar"
ORDER BY 2, 1;
