require 'csv'

function dump (t)
    print(t)
    for k,v in ipairs(t) do print(k,v, type(v)) end
end

headers = true
if arg[2] ~= nil then headers = false end

r,c = csv.reader (arg[1] or 'test1.csv',headers,true)
if c then
    print 'headers'
    dump(c)
end

--[[
row = r:read()
while row do
    dump(row)
    row = r:read()
end
--]]

for row in r:rows() do
    dump(row)  -- can use row:copy() to get unique tables
end





