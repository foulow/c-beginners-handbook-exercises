
CREATE SEQUENCE S_ID_CLIENTES
    START WITH 1
    INCREMENT BY 1
    MINVALUE 1
    NOMAXVALUE
    NOCYCLE
    NOCACHE;

CREATE OR REPLACE PUBLIC SYNONYM S_ID_CLIENTES
    FOR indra.S_ID_CLIENTES;
/
