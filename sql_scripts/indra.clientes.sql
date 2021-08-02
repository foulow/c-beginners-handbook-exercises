--DROP TABLE CLIENTES;
CREATE TABLE CLIENTES (
    ID               NUMBER        PRIMARY KEY,
    NOMBRE           VARCHAR2(31)  NOT NULL,
    APELLIDO1        VARCHAR2(21)  NOT NULL,
    APELLIDO2        VARCHAR2(21)  NOT NULL,
    USUARIO          VARCHAR2(9)   NOT NULL,
    PROGRAMA         VARCHAR2(15)  NOT NULL,
    CREADO_POR       VARCHAR2(25)  NOT NULL,
    CREADO_EN        DATE          NOT NULL,
    ACTUALIZADO_POR  VARCHAR2(25),
    ACTUALIZADO_EN   DATE
);
/

CREATE OR REPLACE PUBLIC SYNONYM CLIENTES FOR indra.CLIENTES;
GRANT SELECT, INSERT, UPDATE, DELETE ON indra.CLIENTES TO PUBLIC;