--DROP TABLE CONSUMOS;
CREATE TABLE CONSUMOS (
    ID               NUMBER        PRIMARY KEY,
    CONSUMO          NUMBER        NOT NULL,
    FECHA_INICIO     DATE          NOT NULL,
    FECHA_CIERRE     DATE          NOT NULL,
    CODIGO_CLIENTE   NUMBER        NOT NULL,
    CREADO_POR       VARCHAR2(25)  NOT NULL,
    CREADO_EN        DATE          NOT NULL,
    ACTUALIZADO_POR  VARCHAR2(25),
    ACTUALIZADO_EN   DATE
);
/

CREATE OR REPLACE PUBLIC SYNONYM CONSUMOS FOR indra.CONSUMOS;
GRANT SELECT, INSERT, UPDATE, DELETE ON indra.CONSUMOS TO PUBLIC;