--DROP TRIGGER indra.T_CLIENTES_LOGS;
CREATE OR REPLACE TRIGGER indra.T_CLIENTES_LOGS
    AFTER INSERT ON indra.CLIENTES
    FOR EACH ROW
DECLARE
    lv_mensage VARCHAR2(250) := CONCAT ('Nuevo registro de usuario nombre: ', :NEW.USUARIO);
BEGIN
    INSERT INTO indra.LOGS
        (MENSAGE, FECHA)
    VALUES
        (lv_mensage, TO_CHAR(SYSDATE, 'YYYY/MM/DD HH12:MI:SS AM'));
END T_CLIENTES_LOGS;
/
