LuaCSV

This is a extension for Lua 5.1 which provides a reader and writer for
CSV files.

This module provides two static functions, parse() and convert(). parse() takes
a csv string and splits it into a table; convert() takes a table and outputs
it as CSV. Note that the delimiter (usually ',') is escaped by putting the
field in double-quotes; double-quotes themselves are escaped by doubling them.

> require 'csv'
> = csv.parse '10,20,30'
{'10','20','30'}
> = csv.parse '10,hello dolly,"one,two,three"'
{'10','hello dolly','one,two,three'}
> = csv.parse '10,hello dolly,"one,""two"",three"\r\n'
{'10','hello dolly','one,"two",three'}

> csv.convert {10,20,'hello dolly'}
'10,20,hello dolly'
> csv.convert {10,20,'hello "dolly"'}
'10,20,"hello ""dolly"""'
> csv.convert {10,20,'hello,you'}
'10,20,"hello,you"'

The reader() function returns a reader object and (optionally) the header line.
The reader object has a method read() for getting the next row, and close()

> rdr,head = csv.reader 'test1.csv'
> head
{'Name "x" is that ','Product','Date','Age'}
> rdr:read()
{'steve','bonzo "dog" catcher','10/10/09',3}
> rdr:read()
{'bonzo','dog','23/04/08',10}
> rdr:read()
{'john','CowCatcher','20/10/09',4}
> rdr:read()
> rdr:close()

Or, you can use the rows() method:

for row in rdr:rows() do
   ....
end

There are three differences between using read() and iterating using rows();
First, the rows() iterator gives you the values in the _same table_ each time,
for efficiency. You will need to copy this table if you aim to build up
a table of rows. The returned table has a method copy() for convenience.

Second, read() will fail by returning nil and an error message,
whereas the rows() iterator will throw an error.

Last, the file is closed automatically at the end of the iteration.

The full signature for reader() is

  csv.reader(filename,header,try_convert,delimiter)

where 'filename' is a filename, or the string 'stdin'.

'header' controls whether the first line is treated as a row of headers,
defaulting to true.

'delimiter' is the character used as a delimiter, usually ',', but may be
';' in locales where the decimal comma is used.

'try_convert' makes the reader attempt to convert the fields to numbers,
also defaulting to true.  Judging from its attempts on the first data row,
it will mark fields as being numerical.  Thereafter, a failed conversion is an
error.

An inconsistent number of fields is also considered an error.

On success, returns a reader object, and also the headers (if specified).

On failure, nil followed by the error string.


  csv.writer(filename,delimiter)

Again, 'filename' is obvious, can also be 'stdout'. This returns a writer with
methods write() and close().  write() is passed a table of values to be
appropriately converted and concatenated; it's up to you to ensure that the number
of fields is consistent, and the object must be explicitly closed.




