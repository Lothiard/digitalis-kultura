-- Az Olimpia feladat megoldásai

-- 1. 1980 utáni, szegedi születésű, egyéni versenyzők névsora
SELECT versenyzok.nev, versenyzok.szul_dat
FROM versenyzok
WHERE year(versenyzok.szul_dat) > 1980 AND versenyzok.szul_hely = "Szeged" AND versenyzok.egyen_csapat = "e"
ORDER BY 1;

-- 2. Vajda Attila eredményei, versenyszámonként, megjegyzésekkel
SELECT versenyszamok.versenyszam, eredmenyek.helyezes, eredmenyek.megjegyzes
FROM versenyszamok, eredmenyek, versenyzok
WHERE versenyszamok.azon = eredmenyek.versenyszam_azon
AND versenyzok.azon = eredmenyek.versenyzo_azon
AND versenyzok.nev = "Vajda Attila";

-- 3. Első helyzést elért országok
SELECT DISTINCT orszagok.orszag
FROM orszagok, versenyzok, eredmenyek
WHERE orszagok.azon = versenyzok.orszag_azon
AND versenyzok.azon = eredmenyek.versenyzo_azon
AND helyezes = 1;

-- 4. Cseh Lászlónál fiatalabb versenyzők adatai
SELECT versenyzok.nev, versenyzok.szul_hely, versenyzok.szul_dat
FROM versenyzok
WHERE versenyzok.szul_dat >
    (SELECT versenyzok.szul_dat
    FROM versenyzok
	WHERE versenyzok.nev = "Cseh László");

-- 5. Versenyzőket nem indító európai országok
SELECT DISTINCT orszagok.*
FROM orszagok, versenyzok
WHERE orszagok.foldresz = "Európa"
AND orszagok.azon NOT IN (versenyzok.orszag_azon);

-- 6. Országok száma, összlakossága, átlagos területe földrészenként
SELECT orszagok.foldresz, COUNT(orszagok.azon), SUM(orszagok.lakossag), AVG(orszagok.terulet)
FROM orszagok
WHERE orszagok.foldresz IS NOT NULL
GROUP BY orszagok.foldresz;

-- 7. A legfiatalabb versenyzőt indító ország
SELECT orszagok.orszag
FROM orszagok, versenyzok
WHERE orszagok.azon = versenyzok.orszag_azon
AND versenyzok.azon =
	(SELECT versenyzok.azon
    FROM versenyzok
    WHERE versenyzok.szul_dat IS NOT NULL
    ORDER BY versenyzok.szul_dat DESC
    LIMIT 1);

-- 8. Az országok által elért pontszámok az új pont_tabla táblába
CREATE TABLE pont_tabla
    SELECT orszagok.orszag, erem_tabla.arany*3 + erem_tabla.ezust*2 + erem_tabla.bronz*1 AS pontok
    FROM erem_tabla, orszagok
    WHERE orszagok.azon = erem_tabla.orszag_azon
    HAVING pontok >= 20;

    INSERT INTO 
	SELECT orszagok.orszag, erem_tabla.arany*3 + erem_tabla.ezust*2 + erem_tabla.bronz*1 AS pontok
    FROM erem_tabla, orszagok
    WHERE orszagok.azon = erem_tabla.orszag_azon
    HAVING pontok >= 20;

-- 9. A magyar női kézilabda csapat névsora életkor szerint növekvő sorrendben

--    Az átalakítandó lekérdezés
-- 	SELECT nev  FROM versenyzok WHERE azon IN (
-- 	    SELECT versenyzo_azon FROM csapattagok 
-- 	    WHERE csapat_azon=(
-- 		SELECT v.azon FROM versenyzok AS v, orszagok AS o 
-- 		WHERE orszag_azon = o.azon AND nev = 'Vízilabda férfi' 
-- 		AND orszag = 'Szerbia'
-- 	    )
-- 	) ORDER BY nev;

SELECT versenyzok.nev
FROM versenyzok
WHERE versenyzok.azon IN
    (SELECT csapattagok.versenyzo_azon
    FROM csapattagok
    WHERE csapat_azon =
        (SELECT versenyzok.azon
        FROM versenyzok, orszagok
        WHERE orszag_azon = orszagok.azon
        AND nev = 'Kézilabda női' AND orszag = 'Magyarország')
    )
ORDER BY nev;

-- 10. A csapatok szul_hely mezőjének feltöltése az indító ország fővárosával

UPDATE versenyzok SET szul_hely =
    (SELECT orszagok.fovaros
    FROM orszagok
    WHERE versenyzok.orszag_azon = orszagok.azon);
