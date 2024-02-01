SELECT segito.nev, AVG(HOUR(ugyelet.befejezes)-HOUR(ugyelet.kezdes))
FROM ugyelet, segito
WHERE segito.id = ugyelet.segitoid
GROUP BY 1;

-- nem adtam hozza a percet es masodpercet mert hat oszinten ki a fasz adta volna hozza
-- igy a jo megoldas valami ilyen lenne:

SELECT segito.nev, AVG(HOUR(ugyelet.befejezes) * 3600 + MINUTE(ugyelet.befejezes) * 60 + SECOND(ugyelet.befejezes) - HOUR(ugyelet.kezdes) * 3600 - MINUTE(ugyelet.kezdes) * 60 - SECOND(ugyelet.kezdes)) / 3600
FROM ugyelet, segito
WHERE segito.id = ugyelet.segitoid
GROUP BY 1;

-- rogton orara konvertalva

SELECT segito.nev, AVG(HOUR(ugyelet.befejezes) + MINUTE(ugyelet.befejezes) / 60 + SECOND(ugyelet.befejezes) / 3600 - HOUR(ugyelet.kezdes) - MINUTE(ugyelet.kezdes) / 60 - SECOND(ugyelet.kezdes) / 3600)
FROM ugyelet, segito
WHERE segito.id = ugyelet.segitoid
GROUP BY 1;