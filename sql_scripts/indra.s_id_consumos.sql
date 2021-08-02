
CREATE SEQUENCE S_ID_CONSUMOS
    INCREMENT BY 1
    START WITH 1
    MINVALUE 1
    NOMAXVALUE
    NOCYCLE
    CACHE 2;

CREATE OR REPLACE PUBLIC SYNONYM S_ID_CONSUMOS
    FOR indra.S_ID_CONSUMOS;
/