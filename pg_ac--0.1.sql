-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION pg_ac" to load this file. \quit


CREATE OR REPLACE FUNCTION ac_build(tsvector)
RETURNS bigint
AS 'pg_ac', 'ac_build'
LANGUAGE C STRICT;

CREATE OR REPLACE FUNCTION ac_destroy(bigint)
RETURNS boolean
AS 'pg_ac', 'ac_destroy'
LANGUAGE C STRICT;

CREATE OR REPLACE FUNCTION ac_destroy_all()
RETURNS boolean
AS 'pg_ac', 'ac_destroy_all'
LANGUAGE C STRICT;

CREATE OR REPLACE FUNCTION ac_search(bigint, tsquery)
RETURNS boolean
AS 'pg_ac', 'ac_search_tsquery'
LANGUAGE C STRICT;

CREATE OR REPLACE FUNCTION ac_search(bigint, text)
RETURNS boolean
AS 'pg_ac', 'ac_search_text'
LANGUAGE C STRICT;

CREATE OR REPLACE FUNCTION ac_rank_simple(bigint, text) 
RETURNS real
AS 'pg_ac', 'ac_rank_simple'
LANGUAGE C STRICT;