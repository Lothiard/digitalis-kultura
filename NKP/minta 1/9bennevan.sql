SELECT csapat.nev
FROM csapat
WHERE Locate(csapat.varos, csapat.nev)
AND csapat.nev <> csapat.varos
AND nemzet In ("angol", "északír", "skót", "walesi");