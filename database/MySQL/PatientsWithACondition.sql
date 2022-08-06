/* Query for patients with
Diabetes Type I
*/
SELECT
    patient_id,
    patient_name,
    conditions
FROM
    Patients
WHERE
    conditions LIKE 'DIAB1%' or conditions LIKE '% DIAB1%'