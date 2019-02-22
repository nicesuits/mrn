[%bs.raw {|require('./IssueTable.css')|}];

let component = ReasonReact.statelessComponent("IssueTable");

let make = _children => {
  ...component,
  render: _self =>
    <table>
      <thead>
        <tr>
          <th className="borderedStyle"> {ReasonReact.string("Id")} </th>
          <th className="borderedStyle"> {ReasonReact.string("Title")} </th>
        </tr>
      </thead>
      <tbody>
        <IssueRow id="1" title="Error in console when clicking Add" />
        <IssueRow id="2" title="Missing button border on panel" />
      </tbody>
    </table>,
};